void removeDots(char *string)
{
    int i, k = 0, flag = 0;
    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '.' && !flag)
        {
            k++;
        }
        else
        {
            if (string[i] == '@')
            {
                flag = 1;
            }
            string[i - k] = string[i];
        }
    }
    string[i - k] = '\0';
}

int numUniqueEmails(char **emails, int emailsSize)
{
    int i, j, k, l, flag = 0;
    if (emailsSize == 1)
    {
        return 1;
    }

    for (i = 0; i < emailsSize; i++)
    {
        for (j = 0; emails[i][j] != '@'; j++)
        {

            if (emails[i][j] == '.')
            {
                removeDots(emails[i]);
            }
            else if (emails[i][j] == '+')
            {
                for (k = j + 1; emails[i][k] != '@'; k++)
                {
                }
                for (l = 0; emails[i][l + k] != '\0'; l++)
                {
                    emails[i][l + j] = emails[i][l + k];
                }
                emails[i][l + j] = emails[i][l + k];
                break;
            }
        }
    }
    for (i = 0; i < emailsSize - 1; i++)
    {
        for (j = i + 1; j < emailsSize; j++)
        {
            if (!strcmp(emails[i], emails[j]))
            {
                flag++;
                break;
            }
        }
    }
    return emailsSize - flag;
}
